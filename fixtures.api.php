<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @param $datas array
 */
function hook_fixtures_create_node_default_alter(&$datas) {
  $datas['node_info'] = array(
    'type'    => $datas['node_type'],
    'uid'     => 1,
    'status'  => 1,
    'promote' => 0,
    'path'    => array('alias'     => 'your-path-alias',
                       'pathauto'  => false), //if you use module pathauto
  );
}


/**
 * @param $datas array
 */
function hook_fixtures_create_node_fields_alter(&$datas) {
  // Load node information.
  // Node_info is "entity_meta_wrapper"-ed.
  $node = $datas['node_info'];
  // Load YAML information.
  $yaml = $datas['yaml'];

  switch($datas['node_type']) {
    case 'page':
      // Do something
      break;

    case 'article':
      // In case you have to deal with files in YAML
      // Get default filepath
      $filepath = variable_get('file_public_path', conf_path() . '/files');
      // Get the file with name entered for key "field_image" into YAML.
      $file = file_save_data(
        file_get_contents($filepath.'/'.$yaml['field_image']),
        'public://'. $yaml['field_image']);
      // And set the image
      $node->field_image->file->set($file);
      break;

    case 'subscription':
      $node->field_count = $yaml['field_count'];
      break;

  }
}
