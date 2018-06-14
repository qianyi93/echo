#pragma once

#include <QDockWidget>
#include "ui_ResPanel.h"
#include "QProperty.hpp"
#include <QDirectoryModel.h>
#include "QPreviewHelper.h"

namespace Studio
{
	class ResPanel : public QDockWidget, public Ui_ResPanel
	{
		Q_OBJECT

	public:
		ResPanel( QWidget* parent=0);
		~ResPanel();

		// call when open project
		void onOpenProject();

	public slots:
		// 选择文件夹
		void onSelectDir(const char* dir);

		// 重新选择当前文件夹
		void reslectCurrentDir();

		// click res
		void onClickedPreviewRes(const char* res);

		// double click res
		void onDoubleClickedPreviewRes(const char* res);

		// node tree widget show menu
		void showMenu(const QPoint& point);

		// show current dir
		void showInExporer();

	protected:
		// reimplement reiszeEvent function
		virtual void resizeEvent(QResizeEvent * e);

	private:
		Echo::String				m_currentDir;
		QT_UI::QDirectoryModel*		m_dirModel;
		QT_UI::QPreviewHelper*		m_previewHelper;
		QMenu*						m_resMenu;			// Mouse right button click
	};
}