$uiFiles = Get-ChildItem -Path . -Filter *.ui

foreach ($uiFile in $uiFiles) {
    $outputFile = $uiFile.BaseName + ".py"
    & pyuic5 -x $uiFile -o $outputFile
}