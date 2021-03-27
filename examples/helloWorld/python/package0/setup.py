import setuptools
print(setuptools.__version__)

setuptools.setup(
    name="pckg0",
    version="1.0.0",
    author="dgerin",
    author_email="",
    description="",
    url="",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: TBC",
        "Operating System :: OS Independent",
    ],
)
