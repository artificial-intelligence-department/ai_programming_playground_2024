import yaml

# Reading YAML file
with open('data.yaml', 'r') as file:
    config = yaml.safe_load(file)

print("Server Host:", config['server']['host'])
print("Server Port:", config['server']['port'])
print("SSL Certificate Path:", config['server']['security']['ssl_cert'])

# Writing to a new YAML file
new_data = {
    'server': {
        'host': '127.0.0.1',
        'port': 9090,
        'security': {
            'enabled': False,
            'ssl_cert': '/new/path/to/certificate.pem',
            'ssl_key': '/new/path/to/key.pem'
        }
    }
}

with open('new_config.yaml', 'w') as file:
    yaml.dump(new_data, file, default_flow_style=False)
