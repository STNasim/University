import re

APACHE_ACCESS_LOG_PATTERN = '^(\S+) (\S+) (\S+) \[([\w:/]+\s[+\-]\d{4})\] "(\S+) (\S+)\s*(\S*)" (\d{3}) (\S+) "([^"]*)" "([^"]*)"'

def log_to_csv(file_path):
    with open(file_path) as filein:
        with open((file_path.rsplit(".", 1)[0]+".csv"), 'w') as fileout:
            for line in filein.readlines():
                match = re.search(APACHE_ACCESS_LOG_PATTERN, line)
                if match is None:
                    continue
                linea = str(match.group(1))+";"+str(match.group(4))+";"+str(match.group(5))+";"+str(match.group(6))+";"+str(match.group(11))+"\n"
                fileout.write(linea)

if __name__ == "__main__":
    log_to_csv("access_log_edw.processed")
    print("Done!")