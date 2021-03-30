/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:03:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/30 18:00:08 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft{
    
    template< class Iter >
    struct iterator_traits {
        typedef typename Iter::difference_type   difference_type;
        typedef	typename Iter::value_type        value_type;
        typedef typename Iter::pointer           pointer;
        typedef typename Iter::reference         reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };
};

#endif