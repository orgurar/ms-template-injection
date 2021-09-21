# Template Injection Self-Implementation

Microsoft Word Template Injection vulnerability is the explotation of the VB macros mechanism found in ms-word template documents.
Microsoft Word has a feature where a user can create a document with a template. Whenever a Word document with a template is being written/read, this templates are being downloaded/used from the local, or remote machine. Thus, the attackers can host a Word Document Template file (.dotm) with malicious macros on their servers. Whenever the victim opens the Word Document, the Document will fetch the malicious template from the attacker's server, and execute it.

## Prerequisites Acknowledgements

This vulnerability contains knowledge from vary edges and mechanisms, here you will be able to find a summary of each of the main topics.

### VBA (Visual Basic for Applications)

VBA is an implementation of Microsoft's event-driven programming language `Visual Basic 6`, and is used in Microsoft Application's [OLE Automation](https://en.wikipedia.org/wiki/OLE_Automation). The `VBA programming language` can be used to write the ms-word `macros` in order to automate the app. In this explotation I have written a `macro` with `VBA` which is downloaded and executed by the opening of the document.

### Microsoft Word and Macro Mechanism

In Word, you can automate frequently used tasks by creating and running `macros`. A macro is a series of commands and instructions that you group together as a single command to accomplish a task automatically. I use this automation to run an injected `VBA` code with the start of the word application, and download the payload.

## Contents

Here you can find a short explanation of each folder and its contents in the project.

### bin

Contains the final payload binary, as well as the malicious `dotm` file.

### data

Contains the VBA code (can be found in `macro_vba_code.vb` file) and the textual file of the binary data. In order to download the `binary` malware without the os blocking the file, I encoded it using `certutil` to a text file, then in the `VBA Macro` I will decode it.

### src

Contains the source code for the payload written in `C++`.

## Built With

- [VBA (Visual Basic For Applications)](https://docs.microsoft.com/en-us/office/vba/api/overview/) - The programming language used to write the macro
- [C++](https://www.cplusplus.com/) - The programming language used to write the payloaded malware
- [Microsoft Office Word](https://templates.office.com/en-us/templates-for-word) - To create a malicious Word document

## Usage

The POC meant for educational purposes only! you can take this guide to the limits but please, don't you dare to do anything to hurt users in your local enviroment, because I know you already thought about it (Well... most of you)

## Authors

- **Or Gur Arie** - Creator and Maintainer - [orgurar](https://gitlab.com/orgurar)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

- [Template Injection](https://attack.mitre.org/techniques/T1221/) - Mitre Attack official report
- [Remote Template Injection](https://blog.sunggwanchoi.com/remote-template-injection/) - MS Template Injection Guide and Blog
- [Inject Macros from a Remote Dotm Template](https://www.ired.team/offensive-security/initial-access/phishing-with-ms-office/inject-macros-from-a-remote-dotm-template-docx-with-macros) - Guide and Lab for Creating a Remote Dotm with Injected Macro
