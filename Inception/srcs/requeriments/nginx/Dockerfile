FROM debian:buster

RUN apt -y update && \
    apt -y upgrade && \
	apt -y install nginx openssl  &&\
    apt-get install -y apt-transport-https

COPY ./tools/default /etc/nginx/sites-available/default
COPY ./tools/index.html /tools/
ARG MYSQL_USER
ARG MYSQL_HOST
ARG MYSQL_PASSWORD
	
RUN rm -rf /etc/nginx/sites-enabled/default && \
	ln -fs /etc/nginx/sites-available/default /etc/nginx/sites-enabled/ && \
    chown -R www-data:www-data /var/www/* && \
    chmod -R 755 /var/www/*

RUN chmod -R 700 /etc/ssl/private && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" -keyout /etc/ssl/private/nginx_server.key -out /etc/ssl/certs/nginx_server.crt && \
    openssl dhparam -out /etc/nginx/dhparam.pem 1000

EXPOSE 443

RUN sed -i "s|fastcgi_param MYSQL_USER;|fastcgi_param MYSQL_USER ${MYSQL_USER};|g" /etc/nginx/sites-available/default && \
sed -i "s|fastcgi_param MYSQL_HOST;|fastcgi_param MYSQL_HOST ${MYSQL_HOST};|g" /etc/nginx/sites-available/default && \
sed -i "s|fastcgi_param MYSQL_PASSWORD;|fastcgi_param MYSQL_PASSWORD ${MYSQL_PASSWORD};|g" /etc/nginx/sites-available/default && \
cp tools/index.html /var/www/html/

CMD ["nginx", "-g", "daemon off;"]