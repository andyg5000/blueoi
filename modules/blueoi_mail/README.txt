USAGE:
* Enable blueoi_mail module and module dependencies
* Configure SMTP module to use preferred SMTP provider /admin/config/system/smtp
* Configure Mail System to use MimeMailSystem_SmtpMailSystem class as Site-wide default MailSystemInterface
* Copy email template from mimemail (/sites/all/modules/contrib/mimemail/theme/mimemail-message.tpl.php) to default theme (/sites/all/themes/<default>/templates/mimemail/mimemail-message.tpl.php) for overriding.
