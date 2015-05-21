<?php

/**
 * Create all nodes
 */
function fixtures_create_nodes() {
  $fixtures = fixtures_get_fixtures('node');
  foreach ($fixtures as $fixture) {
    foreach ($fixture as $node_name => $node_array) {
      $node = fixtures_create_node($node_array);
    }
  }
  return "debugging fixtures";
}

/**`
 * Create single node from YAML array
 */
function fixtures_create_node($node_array) {

  // Create an Entity.
  $values = array(
    'type'    => $node_array['type'],
    'uid'     => $node_array['uid'] ? $node_array['uid'] : 1,
    'status'  => $node_array['status'] ? $node_array['status'] : 0,
    'promote' => $node_array['promote'] ? $node_array['promote'] : 0,
    'path'    => array('alias'     => $node_array['path'] ? $node_array['path'] : NULL,
                       'pathauto'  => $node_array['path'] ? FALSE : TRUE)
  );

  // Implement hook_fixture_create_node_default_alter().
  $data = array(
    'yaml' => $node_array,
    'node_type' => $node_array['type'],
    'node_info' => $values
  );
  drupal_alter('fixtures_create_node_default', $data);

  // Create node.
  $e = entity_create('node', $values);

  // Create a Entity Wrapper of that new Entity.
  $entity = entity_metadata_wrapper('node', $e);

  // Set a title and some text field value.
  $entity->title = $node_array['title'];

  // Set body
  if (isset($node_array['body'])) {
    $entity->body->set(array('value' => $node_array['body'], 'format' => 'full_html'));
  }
  // Set creation date.
  if (isset($node_array['created'])) {
    $entity->created = strtotime($node_array['created']);
  }

  // @todo: it looks like we can't defined the "changed" date. Need to check more.

  // Set Language.
  if (isset($node_array['lang'])) {
    $entity->language = $node_array['lang'];
  }

  // Implement hook_fixture_create_node_fields_alter().
  $data = array(
    'yaml' => $node_array,
    'node_type' => $node_array['type'],
    'node_info' => $entity
  );
  drupal_alter('fixtures_create_node_fields', $data);

  // And save it.
  $entity->save();

  return $entity;
}
