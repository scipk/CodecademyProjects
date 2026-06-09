# Hacking The Fender

import csv, os, json

compromised_users = []

script_dir = os.path.dirname(os.path.abspath(__file__))
passwords_path = os.path.join(script_dir, 'passwords.csv')
compromised_users_path = os.path.join(script_dir, 'compromised_users.txt')
boss_message_path = os.path.join(script_dir, 'boss_message.json')
new_passwords_path = os.path.join(script_dir, 'new_passwords.csv')

# Just to check the directory nonesense
print('Current working directory:', os.getcwd())
print('Loading passwords from:', passwords_path)

with open(passwords_path, newline='') as password_file:
    password_csv = csv.DictReader(password_file)
    for password_row in password_csv:
        # print(password_row['Username'])
        compromised_users.append(password_row['Username'])

with open(compromised_users_path, 'w') as compromised_user_file:
    for compromised_user in compromised_users:
        compromised_user_file.write(compromised_user + "\n")

with open(boss_message_path, 'w') as boss_message:
    boss_message_dict = {"recipient": "The Boss", "message": "Mission Success"}
    json.dump(boss_message_dict, boss_message)

slash_null_sig = """
 _  _     ___   __  ____             
/ )( \   / __) /  \(_  _)            
) \/ (  ( (_ \(  O ) )(              
\____/   \___/ \__/ (__)             
 _  _   __    ___  __ _  ____  ____  
/ )( \ / _\  / __)(  / )(  __)(    \ 
) __ (/    \( (__  )  (  ) _)  ) D ( 
\_)(_/\_/\_/ \___)(__\_)(____)(____/ 
        ____  __     __   ____  _  _ 
 ___   / ___)(  )   / _\ / ___)/ )( \
(___)  \___ \/ (_/\/    \\___ \) __ (
       (____/\____/\_/\_/(____/\_)(_/
 __ _  _  _  __    __                
(  ( \/ )( \(  )  (  )               
/    /) \/ (/ (_/\/ (_/\             
\_)__)\____/\____/\____/
"""

with open(new_passwords_path, 'w') as new_passwords_obj:
    new_passwords_obj.write(slash_null_sig)
    
