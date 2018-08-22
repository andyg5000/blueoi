<?php

/**
 * @file
 * Provides views integration for BlueOI Commerce Revisions.
 */

/**
 * Implements hook_views_data_alter().
 */
function blueoi_commerce_revisions_views_data_alter(&$data) {
  $data['commerce_product_revision']['rendered_revision'] = array(
    'field' => array(
      'title' =>  t('Rendered revision fields'),
      'help' => t('Outputs the rendered value of fields for this revision.'),
      'handler' => 'blueoi_commerce_revisions_views_filter_render_product_revision',
    ),
  );
}
