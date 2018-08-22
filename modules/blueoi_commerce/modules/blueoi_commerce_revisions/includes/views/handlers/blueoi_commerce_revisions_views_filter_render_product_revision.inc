<?php

/**
 * @file
 * Provides a views filter for rendering revisions
 */

class blueoi_commerce_revisions_views_filter_render_product_revision extends views_handler_field {

  /**
   * Overrides views_handler_field::construct().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['revision_id'] = 'revision_id';
    $this->real_field = 'revision_id';
  }

  function query() {}

  function render($values) {
    // Revision id is not returned from $this->get_values().
    $fields = $this->view->display_handler->get_handlers('field');
    $revision_id = (int) $fields['revision_id']->original_value;

    // Load the current revision.
    $entity = entity_revision_load('commerce_product', $revision_id);

    // Load the render arary for the current revision.
    $view = entity_view('commerce_product', array($entity), 'blueoi_commerce_revisions_render');
    return $view;
  }
}
