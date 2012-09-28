<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('uuid')) {
	dl('uuid.' . PHP_SHLIB_SUFFIX);
}
$module = 'uuid';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
echo generate_uuid();
echo "$br\n";
?>
