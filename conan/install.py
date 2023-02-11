#!/usr/bin/python
import subprocess
import argparse
import pathlib

def parse():
    parser = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("build_type", help="Debug or Release", choices=['Debug', 'Release'])
    parser.add_argument("profile", help="Conan Profile")
    return parser.parse_args()

def conan_install(conanfile_directory, args):
    command = ([
        'conan', 'install', f'{conanfile_directory}',
        '--install-folder', f'build/modules', 
        '--settings', f'build_type={args.build_type}',
        '--profile:build', f'{profile_path}',
        '--profile:host', f'{profile_path}',
        '--build', 'missing'
    ])

    try:
        ret = subprocess.run(command)
        ret.check_returncode()
    except Exception as e:
        print(f'Unhandled Exception: {e}')

args = parse()

conan_directory = pathlib.Path(__file__).resolve().parent
profile_path = pathlib.PurePath(conan_directory, "profiles", f'{args.profile}')

conanfile_directories = [
    'multi_layer_ui/engine',
    'multi_layer_ui/ui',
]

for conanfile_directory in conanfile_directories:
    conan_install(conanfile_directory, args)
