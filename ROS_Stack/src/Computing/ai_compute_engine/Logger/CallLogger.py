import logging

class BasicLoggers():
    def __init__(self, logging_level, log_file_path="."):
        logging.basicConfig(
            level=logging_level,
            format="%(asctime)s [%(levelname)s] %(name)s %(message)s",
            handlers=[
                logging.FileHandler(f"{log_file_path}/debug.log"),
                logging.StreamHandler()
            ]
        )
        logging.info('Logger Instantiated')
    def LoggingObject(self):
        return logging
    def getHelp(self):
        print("First make class object and set logging level 'log = BasicLoggers(logging.INFO)'")
        print("Available Logging Levels: DEBUG, INFO, WARNING, ERROR, CRITICAL")
        print("Push messages:")
        print(" logging.debug('This is a debug message')")
        print(" logging.info('This is an info message')")
        print(" logging.warning('This is a warning message')")
        print(" logging.error('This is an error message')")
        print(" logging.critical('This is a critical message')")