#include "qstablewidgetdelegate.h"
#include <QLineEdit>

QSTableWidgetDelegate::QSTableWidgetDelegate(QObject *parent)
	: QItemDelegate(parent)
{

}


QWidget* QSTableWidgetDelegate::createEditor(QWidget *parent,
											 const QStyleOptionViewItem &/* option */,
											 const QModelIndex &/* index */) const
{
	QLineEdit *editor = new QLineEdit(parent);
	connect(editor, SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
	editor->setFont(m_font);
	editor->setFocus();
	return editor;
}

void QSTableWidgetDelegate::setEditorData(QWidget *editor,
									const QModelIndex &index) const
{
	QString value = index.model()->data(index, Qt::EditRole).toString();

	QLineEdit *editLine = static_cast<QLineEdit*>(editor);
	editLine->setText(value);
}

void QSTableWidgetDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
								   const QModelIndex &index) const
{
	QLineEdit *editLine = static_cast<QLineEdit*>(editor);
	QString value = editLine->text();

	model->setData(index, value, Qt::EditRole);
}

void QSTableWidgetDelegate::updateEditorGeometry(QWidget *editor,
										   const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
	editor->setGeometry(option.rect);
}

void QSTableWidgetDelegate::setAFont(QFont a_font)
{
	m_font=a_font;
}

void QSTableWidgetDelegate::commitAndCloseEditor()
{
//    QLineEdit *editLine = qobject_cast<QLineEdit*>(sender());
	QLineEdit *editLine = static_cast<QLineEdit*>(sender());
    emit commitData(editLine);
    emit closeEditor(editLine);
}