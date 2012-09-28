--TEST--
Check for uuid length and randomness
--FILE--
<?php 
  $uuid = generate_uuid();
  $another_uuid = generate_uuid();
  echo strlen($uuid);
  echo "\n";
  echo strlen($another_uuid);
  echo "\n";
  if($uuid != $another_uuid) echo "Yep, it's random!"
?>
--EXPECT--
36
36
Yep, it's random!
