FROM alpine
USER root

# Add file
COPY srcs/init.sh ./tmp/
COPY srcs/start.sh ./tmp/

RUN sh ./tmp/init.sh

COPY srcs/my.cnf /etc/mysql/
COPY srcs/telegraf.conf ./etc/

# Volume
VOLUME ["/var/lib/mysql"]

# Expose Ports
EXPOSE 3306

# start .sh

CMD sh /tmp/start.sh
