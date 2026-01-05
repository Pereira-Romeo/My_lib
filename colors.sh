
bruh=$(cat cron.sh | grep "#")
if [ -z "$bruh" ]; then
  echo "nothing found"
else
  echo "$bruh"
fi

# DSP_HARP_PSSWD=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 13 ; echo '')
# DSP_SERVICE="appapi-dsp:\n    image: ghcr.io/nextcloud/nextcloud-appapi-dsp:latest\n    container_name: \${PREFIX}-context-chat-dsp\n    networks:\n      - onlyoffice\n    environment:\n      - NC_HAPROXY_PASSWORD=${DSP_HARP_PSSWD}\n    volumes:\n      - /var/run/docker.sock:/var/run/docker.sock\n    restart: unless-stopped\n    logging:\n      driver: 'json-file'\n      options:\n        max-size: '5m'\n        max-file: '3'"
# # CONTEXT_CHAT_CRON_JOB='echo \"0 3 * * * /usr/local/bin/php /var/www/html/occ context_chat:scan --all >> /var/log/cron.log 2>&1&& echo \"\$(date '+'\%Y-\%m-\%d \%H:\%M:\%S'') context chat cron job execute\" >> /var/log/bpdoc-cron-remote.log\"'

# sed -i "s|#context_chat_dsp_service_anchor|$DSP_SERVICE|" docker-compose.yml
# # sed -i "s|#context_chat_cron_anchor|$CONTEXT_CHAT_CRON_JOB|" ./cron.sh
# sed -i "s|#context_chat_cron_anchor||" cron.sh


#services:
  #context_chat_dsp_service_anchor

# echo "attempting a sudo ls"
# sudo ls
# if ! [[ $? ]]; then
#     echo "sudo failed exiting programm with error code 1"
#     exit 1
# fi

# for code1 in {0..255}; do
#     for code2 in {0..255}; do
#         for code3 in {0..255}; do
#             echo -e "\e[${code1};${code2};${code3}m"'\\e['"$code1;$code2;$code3"m"\e[0m"
#         done
#     done
# done