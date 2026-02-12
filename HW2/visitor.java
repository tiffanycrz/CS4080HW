package com.crafting interpreters.lox;

class RpnPrinter implements Expr.Visitor<String> {

    // Entry point: convert expression to RPN string
    String print(Expr expr) {
        return expr.accept(this);
    }

    // Binary operation: left right operator
    @Override
    public String visitBinaryExpr(Expr.Binary expr) {
        return expr.left.accept(this) + " " + expr.right.accept(this) + " " + expr.operator.lexeme;
    }

    // Literal: just the number
    @Override
    public String visitLiteralExpr(Expr.Literal expr) {
        return expr.value.toString();
    }
}
