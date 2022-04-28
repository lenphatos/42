service mysql start

# Acces
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# Generate website folder
mkdir /var/www/site && touch /var/www/site/index.php
echo "<?php phpinfo(); ?>" >> /var/www/site/index.php

# SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/site.pem -keyout /etc/nginx/ssl/site.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=simoulin/CN=site"

# Nginx
mv ./tmp/nginx-conf  /etc/nginx/sites-available/
ln -s /etc/nginx/sites-available/nginx-conf /etc/nginx/sites-enabled/
rm -rf /etc/nginx/sites-enabled/default

# Databases
echo "CREATE USER 'simon'@'localhost' IDENTIFIED BY 'simon';" | mysql -u root
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'simon'@'localhost' WITH GRANT OPTION;" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

# Phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
rm -rf phpMyAdmin-4.9.0.1-all-languages.tar.gz
mv phpMyAdmin-4.9.0.1-all-languages phpmyadmin
mv phpmyadmin /var/www/site/
mv ./tmp/phpmyadmin.inc.php /var/www/site/phpmyadmin

# Wordpress
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
rm -rf latest.tar.gz
mv wordpress /var/www/site/
mv /tmp/wp-config.php /var/www/site/wordpress

service php7.3-fpm start
service nginx start
bash
