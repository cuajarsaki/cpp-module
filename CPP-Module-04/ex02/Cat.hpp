/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:41:51 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:41:51 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* m_brain;

public:
    // コンストラクタとデストラクタ
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    
    // 代入演算子オーバーロード
    Cat& operator=(const Cat& other);
    
    // 純粋仮想関数のオーバーライド
    virtual void makeSound() const;
    
    // 追加のメンバー関数
    Brain* getBrain() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif