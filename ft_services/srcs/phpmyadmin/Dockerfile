FROM alpine

# Add files
ADD srcs/init.sh ./
ADD srcs/nginx.conf ./etc/nginx/nginx.conf
ADD srcs/telegraf.conf ./etc/
ADD srcs/config.inc.php /tmp
ADD srcs/start.sh /tmp/

# Expose port
EXPOSE 5000

# start .sh
RUN sh ./init.sh

RUN apk update && apk add supervisor --no-cache
COPY srcs/supervisord.conf /etc/supervisord.conf
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
