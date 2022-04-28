#!/bin/sh

mysql_install_db --user=mysql
tmp=sql_tmp

echo -ne "FLUSH PRIVILEGES;\n
CREATE DATABASE wordpress;\n
GRANT ALL PRIVILEGES ON *.* TO 'mysql'@'%' IDENTIFIED BY 'password' WITH GRANT OPTION;\n
FLUSH PRIVILEGES;\n" >> $tmp 

/usr/bin/mysqld --user=mysql --bootstrap --verbose=0 < $tmp
rm -rf $tmp

while (true) do
	service telegraf status
	if [ $? != 0 ]
	then
		service telegraf restart
	fi

	service mariadb status
        if [ $? != 0 ]
        then
		exec /usr/bin/mysqld --user=mysql
        fi
done
