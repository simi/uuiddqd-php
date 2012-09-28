./configure
make
sudo cp modules/uuid.so /tmp
sudo echo "extension=/tmp/uuid.so" >> `php  -r 'phpinfo();' 2> /dev/null | grep "Loaded Configuration File" | awk '{print $NF}'`
