from PyQt5 import QtWidgets, QtCore
from PyQt5.QtWidgets import QTableWidgetItem
import pandas as pd

from demo import Ui_MainWindow

class DemoTable(QtWidgets.QMainWindow, Ui_MainWindow):  
    #signalrunningriskmanagertext = QtCore.pyqtSignal(str)

    def __init__(self):
        super(DemoTable, self).__init__()
        self.setupUi(self) 

        #Set up table data
        self.tableWidget.setRowCount(25)
        self.tableWidget.setColumnCount(4)

        self.tableWidget.setHorizontalHeaderLabels(['A','B','C','D'])
        d = {'A': range(0,25), 
             'B': range(20,45),
             'C': ['a','b','c','d','e','f','g','h','i','d','s','n','s','t','h','d','t','s','t','s','e','y','d','b','s'],
             'D': ['a','b','c','d','e','f','g','h','i','d','s','n','s','t','h','d','t','s','t','s','e','y','d','b','s']}
        df = pd.DataFrame(data=d)

        for row in range(0,25):
            for column in range(0,4):
                item = QTableWidgetItem(str(df.iloc[row,column]))
                self.tableWidget.setItem(row, column, item)

        #Add filters in column
        self.tableWidgetHeader = self.tableWidget.horizontalHeader()
        self.tableWidgetHeader.sectionClicked.connect(self.columnfilterclicked)
        self.keywords = dict([(i, []) for i in range(self.tableWidget.columnCount())])
        self.checkBoxs = []
        self.col = None

    def slotSelect(self, state):
        for checkbox in self.checkBoxs:
            checkbox.setChecked(QtCore.Qt.Checked == state)

    def menuClose(self):
        self.keywords[self.col] = []
        for element in self.checkBoxs:
            if element.isChecked():
                self.keywords[self.col].append(element.text())
        self.filterdata()
        self.menu.close()

    def clearFilter(self):
        if self.tableWidget.rowCount() > 0:
            for i in range(self.tableWidget.rowCount()):
                self.tableWidget.setRowHidden(i, False)

    def filterdata(self):
        columnsShow = dict([(i, True) for i in range(self.tableWidget.rowCount())])

        for i in range(self.tableWidget.rowCount()):
            for j in range(self.tableWidget.columnCount()):
                item = self.tableWidget.item(i, j)
                if self.keywords[j]:
                    if item.text() not in self.keywords[j]:
                        columnsShow[i] = False
        for key in columnsShow:
            self.tableWidget.setRowHidden(key, not columnsShow[key])

    def columnfilterclicked(self,index):
        self.menu = QtWidgets.QMenu(self)
        self.col = index

        data_unique = []

        self.checkBoxs = []

        checkBox = QtWidgets.QCheckBox("Select all", self.menu)
        checkableAction = QtWidgets.QWidgetAction(self.menu)
        checkableAction.setDefaultWidget(checkBox)
        self.menu.addAction(checkableAction)
        checkBox.setChecked(True)
        checkBox.stateChanged.connect(self.slotSelect)

        for i in range(self.tableWidget.rowCount()):
            if not self.tableWidget.isRowHidden(i):
                item = self.tableWidget.item(i, index)
                if item.text() not in data_unique:
                    data_unique.append(item.text())
                    checkBox = QtWidgets.QCheckBox(item.text(), self.menu)
                    checkBox.setChecked(True)
                    checkableAction = QtWidgets.QWidgetAction(self.menu)
                    checkableAction.setDefaultWidget(checkBox)
                    self.menu.addAction(checkableAction)
                    self.checkBoxs.append(checkBox)

        btn = QtWidgets.QDialogButtonBox(QtWidgets.QDialogButtonBox.Ok | QtWidgets.QDialogButtonBox.Cancel,
                                     QtCore.Qt.Horizontal, self.menu)
        btn.accepted.connect(self.menuClose)
        btn.rejected.connect(self.menu.close)
        checkableAction = QtWidgets.QWidgetAction(self.menu)
        checkableAction.setDefaultWidget(btn)
        self.menu.addAction(checkableAction)

        headerPos = self.tableWidget.mapToGlobal(self.tableWidgetHeader.pos())

        posY = headerPos.y() + self.tableWidgetHeader.height()
        posX = headerPos.x() + self.tableWidgetHeader.sectionPosition(index)
        self.menu.exec_(QtCore.QPoint(posX, posY))

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    window = DemoTable()
    window.show()
    sys.exit(app.exec_())