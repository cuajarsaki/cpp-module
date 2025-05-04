/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:32:01 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:32:01 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongCat.hpp
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    ~WrongCat();
    
    WrongCat& operator=(const WrongCat& other);
    
    // オーバーライドされたメンバー関数（しかし正しく動作しない）
    void makeSound() const; // virtual キーワードがないことに注意
};

#endif