#Download
apk update
apk add --no-cache --upgrade bash
apk add nginx openrc openssl --no-cache
apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

#Nginx
mkdir ./www
adduser -D -g "admin" "admin"
chown -R admin:admin /var/lib/nginx
chown -R admin:admin /www

#wordpress
tar xzf /tmp/latest.tar.gz -C  /www
mv /tmp/wp-config.php /www/wordpress/

# SSL
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=simoulin/CN=ft_services"

openrc
touch /run/openrc/softlevel
