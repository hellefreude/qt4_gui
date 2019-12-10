/**
 * @file /include/ssoni_gui/main_window.hpp
 *
 * @brief Qt based gui for ssoni_gui.
 *
 * @date November 2010
 **/
#ifndef ssoni_gui_MAIN_WINDOW_H
#define ssoni_gui_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/
#ifndef Q_MOC_RUN
#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

#include "robotis_math/robotis_math.h"
#endif

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace ssoni_gui {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function

        void savePeoplePosition(QString x, QString y, QString z);
        void savePixelPosition(QString p_x, QString p_y, QString b_s);
        void saveBoxPosition(QString b_h, QString b_w, QString i_h, QString i_w);

        void saveROIValue(QString roi_x, QString roi_y, QString roi_w, QString roi_h);

        void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_checkbox_use_environment_stateChanged(int state);
        void on_quit_clicked(bool check);
        void on_base_module_clicked();
        void on_arm_module_clicked();
        void on_head_module_clicked();
        void on_action_module_clicked();

        void on_initial_pose_clicked();
        void on_none_module_clicked();

        //manual control

        void on_x_plus_clicked();
        void on_x_minus_clicked();

        void on_y_plus_clicked();
        void on_y_minus_clicked();

        void on_z_plus_clicked();
        void on_z_minus_clicked();

        void on_roll_plus_clicked();
        void on_roll_minus_clicked();

        void on_pitch_plus_clicked();
        void on_pitch_minus_clicked();

        void on_yaw_plus_clicked();
        void on_yaw_minus_clicked();

        void on_motion_num_send_button_clicked();
        void on_dummy_send_button_clicked();
        void on_roi_send_button_clicked();

        void on_button_manual_send_clicked();
        void on_button_manual_clicked();
        void on_button_tracking_clicked();


    /******************************************
    ** Manual connections
    *******************************************/

    void updateLoggingView(); // no idea why this can't connect automatically

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace ssoni_gui

#endif // ssoni_gui_MAIN_WINDOW_H
