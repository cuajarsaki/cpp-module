/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:41:31 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:41:31 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* m_brain;

public:
    // コンストラクタとデストラクタ
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();
    
    // 代入演算子オーバーロード
    Dog& operator=(const Dog& other);
    
    // 純粋仮想関数のオーバーライド
    virtual void makeSound() const;
    
    // 追加のメンバー関数
    Brain* getBrain() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif