#pragma once

#include "transaction.h"

#include <utility>

class TrainingDataTransaction : public Transaction {
public:
    TrainingDataTransaction(const OAuth2Client &oauth, const std::string transactionUrl,
                            const int userId, std::string accessToken)
        : Transaction(oauth, transactionUrl, userId, accessToken) {
    }

    ParsedResponse ListExercises();
    /// TODO: i still dont know what type of url we get (full/partial maybe?)
    ParsedResponse GetExerciseSummary(const std::string &url);

    ParsedResponse GetGpx(const std::string &url);

    ParsedResponse GetTcx(const std::string &url);

    ParsedResponse GetHeartRateZones(const std::string &url);

    ParsedResponse GetAvailableSamples(const std::string &url);

    ParsedResponse GetSamples(const std::string &url);
};