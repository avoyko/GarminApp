#include "table_base.h"


std::string BaseTable::LastRecordDate(const std::string &table_name) {
    DBWorker &db_worker = DBWorker::GetInstance();
    boost::format fmt = boost::format("SELECT * FROM %1% ORDER BY date DESC LIMIT 1;") % table_name;
    mysqlx::SqlResult records = db_worker.SQL(fmt.str());
    mysqlx::Row last_row = records.fetchOne();
    return last_row[0].get<std::string>();
}

bool BaseTable::InsertIntoTable(const std::string &table_name, const std::vector<std::string> &values,
                                std::vector<std::string> column_names) {

    DBWorker &db_worker = DBWorker::GetInstance();
    while (column_names.size() > values.size()) {
        column_names.pop_back();
    }
    boost::format fmt =
            boost::format("INSERT INTO %1%(%2%) VALUES(%3%);") % table_name % Utils::Join(column_names) %
            Utils::Join(values);
    db_worker.SQL(fmt.str());
    return true;
}

