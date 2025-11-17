#ifndef YATZEE_H
#define YATZEE_H

#include <map>
#include <array>
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

class Yatzee : public QWidget
{
    Q_OBJECT

public:
    Yatzee(QWidget *parent = nullptr);
    ~Yatzee();
signals:
    void gameFinished(int finalScore);// 게임 종료 시 최종 점수를 알림
    void backToMenu();// '메뉴로 돌아가기' 버튼용
private slots:
    void onRollButtonClicked();
    void onRecordButtonClicked();
    void onDiceChecked(int diceIndex, bool isChecked);
    void onBackButtonClicked(); // 게임선택메뉴로 돌아가기 버튼
    void onCellClicked(int row, int column); // 테이블 클릭 시 점수 기록을 위한 슬롯 함수
private:
    void setupUI();
    void loadDiceImages();
    void resetRound(); //새 라운드 시작
    void updateDiceDisplay();// m_diceValues에 따라 주사위 버튼 이미지 변경
    void updateScoreTable();// 현재 주사위로 가능한 모든 '예상 점수' 계산 및 표시
    void updateGameInfo();// 라운드, 남은 롤 횟수 등 라벨 업데이트
    void endGame();// 13라운드 종료 시 게임 종료 처리

    //점수 계산 로직
    std::map<QString, int> calculateAllScores(const std::array<int, 5>& dice);
    int calculateScoreFor(const QString& category, const std::array<int, 5>& dice);
private:
    // 1. 레이아웃 (UI 배치)
    QGridLayout* m_mainLayout; // 전체 위젯을 관리할 메인 레이아웃
    QGridLayout* dice_grid_layout; //주사위버튼을 배치할 레이아웃

    // 2. UI 위젯 (화면에 보이는 요소)
    std::array<QPushButton*, 5> m_diceButtons; // 5개의 주사위 버튼
    QPushButton* m_rollButton; // '굴리기' 버튼
    QComboBox* m_categorySelector; // 점수 기록할 카테고리 선택 (드롭다운)
    QPushButton* m_recordButton; // '기록하기' 버튼

    QTableWidget* m_scoreTable; // 점수판 (카테고리명, 예상 점수, 기록된 점수)
    QLabel* m_roundLabel; // "라운드: 1 / 13"
    QLabel* m_rollsLeftLabel; // "남은 롤: 3"
    QLabel* m_currentScoreLabel; // "총 점수: 0"

    // 3. 게임 상태 데이터
    std::array<QPixmap, 7> m_diceImages;
    std::array<int, 5> m_diceValues; // 5개 주사위의 현재 숫자 값 (1~6)
    std::array<bool, 5> m_isKept; // 5개 주사위의 '킵' 상태 (true/false)

    int m_rollCount;
    int m_roundNumber;
    int currentScore;

    QStringList m_categoryNames = {"ACES", "TWOS", "THREES", "FOURS", "FIVES",
                                    "SIXES", "CHANCE", "THREE OF A KIND", "FOUR OF A KIND",
                                   "FULL HOUSE", "SMALL STRAIGHT", "LARGE STRAIGHT", "YATZEE"};

    std::map<QString, int> m_recordedScores; //카테고리별 저장된 스코어
};
#endif // YATZEE_H
