Set WshShell = CreateObject("WScript.Shell")
WshShell.Run chr(34) & "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" & chr(34), 0
WshShell.Run chr(34) & "c:\Users\Ramkumar.E\Documents\c_learning\set_env_c_devlopment.bat" & chr(34), 0
Set WshShell = Nothing