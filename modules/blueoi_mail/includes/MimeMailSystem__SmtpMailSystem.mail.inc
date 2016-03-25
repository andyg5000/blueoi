<?php

/**
 * @file
 * Contains MimeMailSystem__SmtpMailSystem mailsystem class.
 *
 * Defines mailsystem class to use smtp module for sending
 * and mimemail module for rendering html emails.
 */
class MimeMailSystem__SmtpMailSystem implements MailSystemInterface {
  protected $formatClass;
  protected $mailClass;
  public function __construct() {
    if (drupal_autoload_class('MimeMailSystem')) {
      $this->formatClass = new MimeMailSystem;
    }
    else {
      $this->formatClass = new DefaultMailSystem;
    }
    if (drupal_autoload_class('SmtpMailSystem')) {
      $this->mailClass = new SmtpMailSystem;
    }
    else {
      $this->mailClass = new DefaultMailSystem;
    }
  }
  public function format(array $message) {
    return $this->formatClass->format($message);
  }
  public function mail(array $message) {
    return $this->mailClass->mail($message);
  }
}
