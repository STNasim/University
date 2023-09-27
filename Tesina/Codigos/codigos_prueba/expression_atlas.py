import sys
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWebEngineWidgets import QWebEngineView
from PyQt5.QtCore import QUrl

def main():
    app = QApplication(sys.argv)
    view = QWebEngineView()

    gene = "ENSG00000141510"
    url = f"https://www.ebi.ac.uk/gxa/genes/{gene}"
    view.load(QUrl(url))
    view.show()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()