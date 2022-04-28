#Download
apk update
apk add --no-cache --upgrade bash
apk add openrc nginx openssl --no-cache
apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

#Nginx
mkdir ./www
echo 'root:password' | chpasswd
chown -R root:root /var/lib/nginx
chown -R root:root /www


#PhpMyAdmin
mkdir -p /var/run/php
wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /www
mv /tmp/config.inc.php /www/phpmyadmin

#create ['TempDir'] for phpmyadmin
mkdir /www/phpmyadmin/tmp
chmod 777 /www/phpmyadmin/tmp

# SSL
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=simoulin/CN=ft_services"

openrc
touch /run/openrc/softlevel
