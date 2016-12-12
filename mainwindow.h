#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
	void keyPressEvent(QKeyEvent *event);

private slots:

    void on_apply_bloom_check_clicked(bool checked);

    void on_start_button_clicked();

	void on_pause_button_clicked();

	void on_stop_button_clicked();

    void on_gravitational_constant_spin_valueChanged(const QString &arg1);

    void on_gravitational_constant_spin_valueChanged(double arg1);

    void on_softening_factor_spin_valueChanged(double arg1);

    void on_softening_factor_spin_valueChanged(const QString &arg1);

    void on_exposure_spin_valueChanged(double arg1);
	
	void on_exposure_spin_valueChanged(const QString &arg1 );

    void on_red_threshold_spin_valueChanged(const QString &arg1);

    void on_red_threshold_spin_valueChanged(double arg1);

    void on_green_threshold_spin_valueChanged(const QString &arg1);

    void on_green_threshold_spin_valueChanged(double arg1);

    void on_blue_threshold_spin_valueChanged(const QString &arg1);

    void on_blue_threshold_spin_valueChanged(double arg1);

    void on_particle_size_spin_valueChanged(const QString &arg1);

	void on_particle_size_spin_valueChanged(double arg1);

    void on_initial_conditions_box_activated(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
