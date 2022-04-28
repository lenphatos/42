apk update
apk add --no-cache --upgrade bash
apk add nginx openrc openssl openssh --no-cache
apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

mkdir ./www
echo 'root:password' | chpasswd
chown -R root:root /var/lib/nginx
chown -R root:root /www

# SSL
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=simoulin/CN=ft_services"

# SSH
adduser -D admin
echo "admin:password"|chpasswd
ssh-keygen -A

openrc
touch /run/openrc/softlevel
