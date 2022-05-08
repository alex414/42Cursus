FROM debian:buster

COPY conf/50-server.cnf ./server/
COPY conf/create_wordpress.sql ./server/
COPY conf/mariadb_wordpress.sql ./server/
COPY conf/create_admin.sql ./server/

ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASS
ARG MYSQL_USER_ADM
ARG MYSQL_PASSWORD_ADM

RUN apt -y update && \
	apt -y install mariadb-server ; \
	apt -y upgrade

RUN sed -i "s/MYSQL_USER/${MYSQL_USER}/g" /server/create_wordpress.sql
RUN sed -i "s/MYSQL_PASSWORD/${MYSQL_PASSWORD}/g" /server/create_wordpress.sql
RUN sed -i "s/MYSQL_ROOT_PASS/${MYSQL_ROOT_PASS}/g" /server/create_admin.sql
RUN sed -i "s/MYSQL_USER_ADM/${MYSQL_USER_ADM}/g" /server/create_admin.sql
RUN sed -i "s/MYSQL_PASSWORD_ADM/${MYSQL_PASSWORD_ADM}/g" /server/create_admin.sql
RUN rm -f /etc/mysql/mariadb.conf.d/50-server.cnf
RUN	cp /server/50-server.cnf /etc/mysql/mariadb.conf.d/
RUN service mysql restart && mysql -i < /server/create_wordpress.sql && mysql -i < /server/mariadb_wordpress.sql && mysql -i < /server/create_admin.sql

CMD [ "mysqld" ]
