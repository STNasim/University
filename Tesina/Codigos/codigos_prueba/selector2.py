from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QComboBox, QLabel

class SelectorWidget(QWidget):
    def __init__(self):
        super().__init__()

        layout = QVBoxLayout(self)

        self.comboBox = QComboBox(self)
        self.label = QLabel("Select an option", self)

        layout.addWidget(self.comboBox)
        layout.addWidget(self.label)

    def set_options(self, options):
        self.comboBox.clear()
        self.comboBox.addItems(options)

    def set_label(self, text):
        self.label.setText(text)

if __name__ == '__main__':
    app = QApplication([])
    selectorWidget = SelectorWidget()
    selectorWidget.set_options(["Option 1", "Option 2", "Option 3"])
    selectorWidget.set_label("Custom Label")
    selectorWidget.show()
    app.exec()