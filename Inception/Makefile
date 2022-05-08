all: help

help:
	@clear
	@echo "\n${B}DESCRIPTION\n"
	@echo "Run:Init all services, containers, images and volumes."
	@echo "Clean:Stops and removes the containers with their images."
	@echo "Fclean:Performs the same task as clean command, and now removes volumes."
	@echo "Re:Clean and execute all.\n"

clean:
	clear
	@sh /root/Escritorio/ft_inception/srcs/scripts/reset.sh

fclean:
	clear
	@sh /root/Escritorio/ft_inception/srcs/scripts/reset.sh 2>/dev/null
	@docker volume prune -f 2>/dev/null
	@sh /root/Escritorio/ft_inception/srcs/scripts/rm_vol.sh
	@sudo rm -rf /root/data

prune:
	docker system prune

run:
	mkdir -p /root/data/db
	@mkdir -p /root/data/wp
	docker-compose -f ./srcs/docker-compose.yml up -d --build

re:
	make fclean
	@make run 


