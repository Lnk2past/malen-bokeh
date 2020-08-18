import os
from distutils.command.install_headers import install_headers as install_headers_orig
from setuptools import setup, find_namespace_packages

about = {}
here = os.path.abspath(os.path.dirname(__file__))
with open(os.path.join(here, 'malen', 'bokeh', '__version__.py'), 'r') as f:
    exec(f.read(), about)

with open('README.md', 'r') as f:
    readme = f.read()

with open('requirements.txt', 'r') as f:
    install_requires = f.read().split('\n')

# https://stackoverflow.com/a/50114715
class install_headers(install_headers_orig):
    def run(self):
        headers = self.distribution.headers or []
        for header in headers:
            dst = os.path.join(self.install_dir, os.path.dirname(header))
            self.mkpath(dst)
            (out, _) = self.copy_file(header, dst)
            self.outfiles.append(out)

setup(
    name=about['__title__'],
    version=about['__version__'],
    packages=find_namespace_packages(),
    author=about['__author__'],
    description=about['__description__'],
    long_description=readme,
    long_description_content_type='text/markdown',
    license=about['__license__'],
    url=about['__url__'],
    install_requires=install_requires,
    headers=['include/malen/bokeh.h'],
    cmdclass={'install_headers': install_headers},
)