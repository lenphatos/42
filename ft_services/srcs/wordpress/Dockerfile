FROM alpine

# Add files
ADD http://wordpress.org/latest.tar.gz /tmp
ADD srcs/supervisor.conf /etc/supervisor.conf
ADD srcs/init.sh ./
ADD srcs/wp-config.php /tmp/
ADD srcs/nginx.conf ./etc/nginx/nginx.conf
ADD srcs/telegraf.conf /etc/
ADD srcs/start.sh /tmp/

# Expose Ports
EXPOSE 5050

# start sh
RUN sh ./init.sh
RUN apk add supervisor && mkdir -p /var/log/supervisor && mkdir -p /etc/supervisor/conf.d
CMD ["supervisord", "-c", "/etc/supervisor.conf"]
