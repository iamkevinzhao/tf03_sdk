#ifndef APD_PAGE_H
#define APD_PAGE_H

#include <QObject>
#include <QElapsedTimer>
#include <memory>

struct MeasureDevel;
// #include <QLayout>
class QLayout;
class DistanceOverTimeChart;
namespace QtCharts {
  class QChartView;
}
class QLabel;
class QPushButton;
class QProgressBar;
class QLineEdit;
class QElapsedTimer;
class Driver;
class CommandEchoHandler;

class APDPage : public QObject
{
  Q_OBJECT
public:
  APDPage();
  ~APDPage();
  void SetPlotLayout(QLayout* layout);
  void SetAPDDisplayLabel(QLabel* label);
  void SetTemperatureDisplayLabel(QLabel* label);
  void SetStartPushButton(QPushButton* button);
  void SetProgressBar(QProgressBar* progress);
  void SetAPDFromLineEdit(QLineEdit* edit);
  void SetAPDToLineEdit(QLineEdit* edit);
  void SetThresholdLineEdit(QLineEdit* edit);
  void SetDriver(std::shared_ptr<Driver> driver);
  void SetCmdEchoHandler(std::shared_ptr<CommandEchoHandler> echoes);
  bool Initialize();
  void IncomingMeasure(const MeasureDevel& measure);
  void Update();
public slots:
  void OnStartButtonClicked();
private:
  void OnStart();
  void OnStop();
  QLayout* plot_layout_ = nullptr;
  QtCharts::QChartView* main_chart_view_ = nullptr;
  DistanceOverTimeChart* main_chart_ = nullptr;
  QLabel* apd_label_ = nullptr;
  QLabel* temp_label_ = nullptr;
  QPushButton* start_button_ = nullptr;
  QProgressBar* progress_bar_ = nullptr;
  QLineEdit* apd_from_edit_ = nullptr;
  QLineEdit* apd_to_edit_ = nullptr;
  QLineEdit* threshold_edit_ = nullptr;
  const QString kStartButtonStart = "Start";
  const QString kStartButtonStop = "Stop";
  int apd_from_;
  int apd_to_;
  int threshold_;
  int apd_cmd_;
  int apd_step_ = 1;
  bool ongoing_ = false;
  std::shared_ptr<QElapsedTimer> timeout_;
  std::shared_ptr<QElapsedTimer> timer_;
  std::shared_ptr<Driver> driver_;
  std::shared_ptr<CommandEchoHandler> echoes_;
  const char kSetAPDCmdID = 0x40;
};

#endif // APD_PAGE_H
