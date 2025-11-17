#include "yatzee.h"
#include <QRandomGenerator>
#include <QHeaderView>

Yatzee::Yatzee(QWidget *parent)
    : QWidget(parent),
    m_rollCount(3),
    m_roundNumber(1),
    currentScore(0)
{
    for (const QString& category : m_categoryNames) {
        m_recordedScores[category] = -1;
    }

    for(int i = 0; i < 5; i++){
        m_isKept[i] = false;
        m_diceValues[i] = 1;
    }

    loadDiceImages();
    setupUI();
    resetRound();
    connect(m_rollButton, &QPushButton::clicked, this, &Yatzee::onRollButtonClicked);

}

Yatzee::~Yatzee()
{

}

void Yatzee::setupUI()
{
    this->setStyleSheet("background-color: #f0f0f0;");
    this->setFixedSize(900, 600);

    m_roundLabel = new QLabel(QString("Round: %1 / 13").arg(m_roundNumber));
    QFont infoFont = m_roundLabel->font(); //폰트 추출
    infoFont.setPointSize(12);
    infoFont.setBold(true);
    m_roundLabel->setFont(infoFont);

    m_rollsLeftLabel = new QLabel(QString("Rolls Left: %1").arg(m_rollCount));
    m_rollsLeftLabel->setFont(infoFont);

    m_currentScoreLabel = new QLabel(QString("Current Score: %1").arg(currentScore));
    m_currentScoreLabel->setFont(infoFont);

    m_rollButton = new QPushButton("Roll Dice");

    dice_grid_layout = new QGridLayout();

    for (int i = 0; i < m_diceButtons.size(); i++){
        m_diceButtons[i] = new QPushButton();
        m_diceButtons[i]->setFixedSize(80,80);

        m_diceButtons[i]->setIcon(QIcon(m_diceImages[i+1]));
        m_diceButtons[i]->setIconSize(QSize(60, 60));
        m_diceButtons[i]->setCheckable(true);
        m_diceButtons[i]->setFocusPolicy(Qt::NoFocus);
        m_diceButtons[i]->setStyleSheet(
            "QPushButton { "
            "    border: 2px solid transparent;"  // 평소엔 테두리 없음
            "    border-radius: 10px;"
            "    background-color: white;"
            "}"
            "QPushButton:checked {"
            "    border: 4px solid #ff5555;"      // Keep 되면 굵은 빨간 테두리
            "    background-color: #ffeeee;"      // 배경도 살짝 붉게
            "}"
            );
        connect(m_diceButtons[i], &QPushButton::toggled, this, [this, i](bool checked) {
            onDiceChecked(i, checked);
        });
    }

    dice_grid_layout->addWidget(m_diceButtons[0],0,0);
    dice_grid_layout->addWidget(m_diceButtons[1],0,2);
    dice_grid_layout->addWidget(m_diceButtons[2],1,1);
    dice_grid_layout->addWidget(m_diceButtons[3],2,0);
    dice_grid_layout->addWidget(m_diceButtons[4],2,2);

    m_scoreTable = new QTableWidget(13, 3);

    QStringList headers;
    headers << "Category" << "Score" << "Potential";
    m_scoreTable->setHorizontalHeaderLabels(headers);

    m_scoreTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_scoreTable->verticalHeader()->setVisible(false);
    m_scoreTable->horizontalHeader()->setVisible(true);
    m_scoreTable->setSelectionMode(QAbstractItemView::NoSelection);
    m_scoreTable->setFocusPolicy(Qt::NoFocus);

    for (int i = 0; i < m_categoryNames.size(); i++){
        QTableWidgetItem* itemCat = new QTableWidgetItem(m_categoryNames[i]);
        itemCat->setTextAlignment(Qt::AlignCenter);
        itemCat->setFlags(Qt::ItemIsEnabled);
        m_scoreTable->setItem(i,0,itemCat);

        QTableWidgetItem* itemScore = new QTableWidgetItem("");
        itemScore->setTextAlignment(Qt::AlignCenter);
        itemScore->setFlags(Qt::ItemIsEnabled);
        m_scoreTable->setItem(i, 1, itemScore);

        QTableWidgetItem* itemPot = new QTableWidgetItem("");
        itemPot->setTextAlignment(Qt::AlignCenter);
        itemPot->setFlags(Qt::ItemIsEnabled);
        m_scoreTable->setItem(i, 2, itemPot);
    }

    m_scoreTable->setColumnWidth(0, 140);
    m_scoreTable->setColumnWidth(1, 80);
    m_scoreTable->setColumnWidth(2, 80);
    m_scoreTable->setAlternatingRowColors(true);

    m_mainLayout = new QGridLayout(this);
    m_mainLayout->addWidget(m_roundLabel, 0, 0);
    m_mainLayout->addWidget(m_rollsLeftLabel, 0, 1);
    m_mainLayout->addWidget(m_currentScoreLabel,0,2);
    m_scoreTable->setStyleSheet(
        "QTableWidget {"
        "   background-color: #ffffff;"
        "   alternate-background-color: #f2f2f2;"
        "   gridline-color: #d0d0d0;"
        "   border: 2px solid #333333;"
        "   font-size: 14px;"
        // [추가] 선택 색상을 투명하게 설정하여 시각적으로 선택 안 된 것처럼 보이게 함
        "   selection-background-color: transparent;"
        "   selection-color: black;"
        "}"
        "QHeaderView::section {"
        "   background-color: #404040;"
        "   color: white;"
        "   padding: 4px;"
        "   border: 1px solid #6c6c6c;"
        "   font-weight: bold;"
        "}"
        // [추가] 아이템이 선택되거나 포커스될 때 배경/테두리 제거
        "QTableWidget::item:selected {"
        "   background-color: transparent;"
        "   color: black;" // 글자색 유지
        "}"
        "QTableWidget::item:focus {"
        "   background-color: transparent;"
        "   border: none;" // 점선 테두리 제거
        "}"
        );

    m_mainLayout->addWidget(m_scoreTable, 1, 0, 4, 2);
    m_mainLayout->addWidget(m_rollButton, 1, 2);

    m_mainLayout->addLayout(dice_grid_layout, 2, 2, 3, 1);
    connect(m_scoreTable, &QTableWidget::cellClicked, this, &Yatzee::onCellClicked);
}

void Yatzee::loadDiceImages()
{
    m_diceImages[1] = QPixmap(":/images/dice-six-faces-one.png");
    m_diceImages[2] = QPixmap(":/images/dice-six-faces-two.png");
    m_diceImages[3] = QPixmap(":/images/dice-six-faces-three.png");
    m_diceImages[4] = QPixmap(":/images/dice-six-faces-four.png");
    m_diceImages[5] = QPixmap(":/images/dice-six-faces-five.png");
    m_diceImages[6] = QPixmap(":/images/dice-six-faces-six.png");
}

void Yatzee::resetRound()
{
    m_rollCount = 3;
    for(int i=0; i<5; ++i) m_isKept[i] = false;
    for(auto btn : m_diceButtons){
        if(btn){
            btn->setChecked(false);
            btn->setCheckable(false);
        }
    }
    updateGameInfo(); // 라벨 업데이트
    updateScoreTable(); // 예상 점수판 업데이트
}

void Yatzee::updateDiceDisplay()
{
    for(int i = 0; i < 5; i++){
        int val = m_diceValues[i];
        if(val >= 1 && val <= 6)
            m_diceButtons[i]->setIcon(QIcon(m_diceImages[val]));
    }
}

void Yatzee::updateScoreTable()
{
    for(int i = 0; i < m_categoryNames.size(); i++) {
        QString category = m_categoryNames[i];
        int recordedScore = m_recordedScores[category];

        QTableWidgetItem* scoreItem = m_scoreTable->item(i,1);
        QTableWidgetItem* potentialItem = m_scoreTable->item(i,2);

        if(recordedScore != -1) {
            scoreItem->setText(QString::number(recordedScore));
            potentialItem->setText("-");
            potentialItem->setForeground(Qt::black);
        }
        else {
            if(m_rollCount == 3) {
                potentialItem->setText("");
                potentialItem->setForeground(Qt::black);
            } else {
                int potential = calculateScoreFor(category, m_diceValues);
                potentialItem->setText(QString::number(potential));
                potentialItem->setForeground(Qt::red);
            }
        }
    }
}

void Yatzee::updateGameInfo()
{
    m_roundLabel->setText(QString("Round: %1 / 13").arg(m_roundNumber));
    m_rollsLeftLabel->setText(QString("Rolls Left: %1").arg(m_rollCount));

    currentScore = 0;
    for(auto const& [key, val] : m_recordedScores) {
        if(val != -1) currentScore += val;
    }
    m_currentScoreLabel->setText(QString("Current Score: %1").arg(currentScore));
}

void Yatzee::endGame()
{
    m_rollButton->setEnabled(false);
    m_rollButton->setText("Game Over");

    QMessageBox::information(this, "Game Over",
                             QString("Game Finished!\nYour Total Score: %1").arg(currentScore));

    emit gameFinished(currentScore);
}

std::map<QString, int> Yatzee::calculateAllScores(const std::array<int, 5>& dice)
{
    std::map<QString, int> allScores;
    for(const QString& category : m_categoryNames){
        allScores[category] = calculateScoreFor(category, dice);
    }
    return allScores;
}

int Yatzee::calculateScoreFor(const QString& category, const std::array<int, 5>& dice)
{
    std::array<int,7> counts;
    counts.fill(0);
    for(int i = 0; i < 5; i++){
        counts[dice[i]] += 1;
    }
    int sum = 0;
    int totalDiceSum = 0;
    for(int d : dice) totalDiceSum += d;

    if(category == "ACES") {
        for(auto a : dice) if(a==1) sum+= a;
    }
    else if(category == "TWOS") {
        for(auto a: dice) if(a==2) sum+= a;
    }
    else if(category == "THREES") {
        for(auto a: dice) if(a==3) sum+= a;
    }
    else if(category == "FOURS") {
        for(auto a: dice) if(a==4) sum+= a;
    }
    else if(category == "FIVES") {
        for(auto a: dice) if(a==5) sum+= a;
    }
    else if(category == "SIXES") {
        for(auto a: dice) if(a==6) sum+= a;
    }
    else if(category == "CHANCE") {
        sum = totalDiceSum;
    }
    else if(category == "THREE OF A KIND") {
        for(int i = 1; i <= 6; i++){
            if(counts[i] >= 3){
                sum = totalDiceSum;
                break;
            }
        }
    }
    else if(category == "FOUR OF A KIND") {
        for(int i = 1; i <= 6; i++){
            if(counts[i] >= 4){
                sum = totalDiceSum;
                break;
            }
        }
    }
    else if(category == "FULL HOUSE") {
        bool two_found = false;
        bool three_found = false;
        for(int i = 1; i <= 6; i++){
            if(counts[i] == 3) three_found = true;
            if(counts[i] == 2) two_found = true;
        }
        if(two_found && three_found) sum = 25;
    }
    else if(category == "SMALL STRAIGHT") {

        bool p1 = (counts[1] && counts[2] && counts[3] && counts[4]);
        bool p2 = (counts[2] && counts[3] && counts[4] && counts[5]);
        bool p3 = (counts[3] && counts[4] && counts[5] && counts[6]);
        if(p1 || p2 || p3) sum = 30;
    }
    else if(category == "LARGE STRAIGHT") {
        bool p1 = (counts[1] && counts[2] && counts[3] && counts[4] && counts[5]);
        bool p2 = (counts[2] && counts[3] && counts[4] && counts[5] && counts[6]);
        if(p1 || p2) sum = 40;
    }
    else if(category == "YATZEE") {
        for(int i = 1; i <= 6; i++){
            if(counts[i] == 5){
                sum = 50;
                break;
            }
        }
    }
    return sum;
}

void Yatzee::onCellClicked(int row, int column)
{
    if (m_rollCount == 3) return;
    if (column != 2) return;

    QString category = m_categoryNames[row];

    if (m_recordedScores[category] != -1) {
        return;
    }

    int score = calculateScoreFor(category, m_diceValues);
    m_recordedScores[category] = score;

    if (m_roundNumber < 13) {
        m_roundNumber++;
        resetRound();
    } else {
        updateGameInfo();
        updateScoreTable();
        endGame();
    }
}

void Yatzee::onRollButtonClicked()
{
    if(m_rollCount > 0){
        for(int i = 0; i < 5; i++){
            if(!m_isKept[i]){
                int randomValue = QRandomGenerator::global()->bounded(1,7);
                m_diceValues[i] = randomValue;
                m_diceButtons[i]->setIcon(QIcon(m_diceImages[randomValue]));
            }
        }
        m_rollCount--;

        updateGameInfo();
        updateScoreTable();
    }
}

void Yatzee::onRecordButtonClicked()
{

}

void Yatzee::onDiceChecked(int diceIndex, bool isChecked)
{
    m_isKept[diceIndex] = isChecked;
}

void Yatzee::onBackButtonClicked()
{

}
