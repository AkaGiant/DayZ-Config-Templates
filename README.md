# DayZ Config Templates

This project provides a collection of templates for handling configuration files in DayZ mods. Each folder contains a different approach or setup for managing configs, making it easier to start new projects or learn best practices.

## Structure

### Basic

The simplest setup for DayZ configs. Ideal for small mods.

#### Usage

Rename the following files
TemplateConfig.c | Suggested: YourModNameConfig.c
TemplateConstants.c | Suggested: YourModNameConstants.c

Locate the string "TemplateConstants" in every file and rename it to the class inside of the file TemplateConstants.c

More templates will be added soon, each demonstrating different methods or advanced setups.

## Usage

1. Browse the folders to find a template that fits your needs.
2. Copy the template files into your own project.
3. Customize the configs as required for your mod.
4. Anything marked as "Template" will need to be changed to your mod

## Contributing

Feel free to suggest new templates or improvements by opening an issue or pull request.

## License

This project is open source. See the [LICENSE](LICENSE)

## Output

In [Output](output.json) you will find what the config file should look like when compiled and ran.
