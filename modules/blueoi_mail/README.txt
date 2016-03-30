==================================
 USAGE / CONFIGURATION:
==================================

* Enable blueoi_mail module and module dependencies

* Create new Email HTML text format used for outgoing emails admin/config/content/formats
    - Ensure roles is set only to administrator
    - Enable these filters: "Convert line breaks into HTML", "Convert URLS into links", "Convert Media tags to markup", and "Correct faulty and chopped off html"

* Configure mimemail module admin/config/system/mimemail
    - Ensure that "Link images only" is checked (note: disabling this will cause issues with emails sent via rules and or webform modules.
    - Ensure that "E-mail format" is set to your newly created "Email HTML" text format

* Configure SMTP module to use preferred SMTP provider /admin/config/system/smtp
    - Ensure that "Allow to send e-mails formatted as Html" is checked

* Configure Mail System to use MimeMailSystem_SmtpMailSystem class as Site-wide default MailSystemInterface and module classes admin/config/system/mailsystem

* Copy email template from mimemail (/sites/all/modules/contrib/mimemail/theme/mimemail-message.tpl.php) to default theme (/sites/all/themes/<default>/templates/mimemail/mimemail-message.tpl.php) for overriding.
