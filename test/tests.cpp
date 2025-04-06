// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, OnFromOffChangesToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, OffFromWaitChangesToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, CoinAddsCashInWaitState) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, CoinAddsCashInAcceptState) {
    Automata a;
    a.on();
    a.coin(100);
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, CoinWithNegativeAmountCallsCancel) {
    Automata a;
    a.on();
    a.coin(-50);
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, GetMenuReturnsCorrectItems) {
    Automata a;
    std::vector<std::string> expected = {
        "Espresso 130", "Cappuccino 150", "Latte 170",
        "Americano 120", "Raf 200"
    };
    EXPECT_EQ(a.getMenu(), expected);
}

TEST(AutomataTest, CancelResetsToWait) {
    Automata a;
    a.on();
    a.coin(100);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, ChoiceWithEnoughMoneyReducesCash) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("Espresso");
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, ChoiceWithInsufficientMoneyCallsCancel) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice("Latte");
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, ChoiceWithInvalidDrinkCallsCancel) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice("Mocha");
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CookFromCheckChangesToCookThenWait) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("Espresso");
    a.cook();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, FinishWithoutCookingDoesNotChangeState) {
    Automata a;
    a.on();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, MultipleDrinksSubtractCashCorrectly) {
    Automata a;
    a.on();
    a.coin(400);
    a.choice("Latte");       // 170
    a.cook();
    a.coin(100);
    a.choice("Americano");   // 120
    a.cook();
    EXPECT_EQ(a.getState(), WAIT);
}

