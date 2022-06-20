#pragma once

#include <Poco/Util/OptionProcessor.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/Validator.h>
#include <Poco/Util/OptionCallback.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/Validator.h>
#include <Poco/Util/IntValidator.h>
#include <Poco/Util/JSONConfiguration.h>
#include <Poco/Util/SystemConfiguration.h>

#include <iostream>


namespace core
{
class argument_parser
{
public:
    explicit argument_parser() : _stopProcessing {false}
    {
        setup_options();
        load();
    }

    void load()
    {
        try 
        {
            _json_config.load("../../../config.json");
        } 
        catch (...) 
        {
            // oops...
        }

        _json_config.getBool("enable_ui", false);
    }

    bool parse(int argc, char** argv)
    {
        Poco::Util::OptionProcessor processor(_options);
        processor.setUnixStyle(true);

        std::vector<std::string> args;
        args.push_back("-l=1");

        for (auto i = 1; i < argc; ++i)
            args.push_back(std::string(argv[i]));

        std::string name;
        std::string value;
        for (auto&& arg : args)
        {
            if (_stopProcessing)
                return false;

            if (!processor.process(arg, name, value))
                continue;

            const auto& option = _options.getOption(name);

            if (option.validator())
                option.validator()->validate(option, value);

            if (option.callback())
                option.callback()->invoke(name, value);

            if (!option.binding().empty())
            {
                auto option_config = option.config();
                _json_config.setString("", "");
            }
        }

        if (_stopProcessing)
            return false;

        // processor.checkRequired();

        return true;
    }

    void show_version(const std::string& name, const std::string& value)
    {
        (void)name; (void)value;

        std::cout << "sfml_ui" << " - " << "0.1.0" << std::endl;

        _stopProcessing = true;
    }

    void show_help(const std::string& name, const std::string& value)
    {
        (void)name; (void)value;

        Poco::Util::HelpFormatter helpFormatter(_options);
        helpFormatter.setCommand("sfml_ui");
        helpFormatter.setUsage("<OPTIONS>");
        helpFormatter.setHeader("Proof of concept for a simple SFML UI");
        helpFormatter.format(std::cout);

        _stopProcessing = true;
    }

    std::string get()
    {
        _options.hasOption("");

        return "";
    }

private:
    bool _stopProcessing;
    Poco::Util::OptionSet _options;
    Poco::Util::JSONConfiguration _json_config;
    
    void setup_options()
    {
        _options.addOption(
            Poco::Util::Option("help", "h", "Display help information")
            .required(false)
            .repeatable(false)
            .callback(Poco::Util::OptionCallback<argument_parser>(this, &argument_parser::show_help)));

        _options.addOption(
            Poco::Util::Option("version", "v", "Display version information")
            .required(false)
            .repeatable(false)
            .callback(Poco::Util::OptionCallback<argument_parser>(this, &argument_parser::show_version)));

        _options.addOption(
            Poco::Util::Option("enable_ui", "u", "Enable UI")
            .binding("enable_ui")
            .required(false)
            .repeatable(false));

        _options.addOption(
            Poco::Util::Option("log_level", "l", "Logger Level")
            .binding("log_level")
            .required(false)
            .repeatable(false)
            .argument("<LEVEL>"));
    }
};

}
