#ifndef XTHREE_ANIMATION_UTILS_HPP
#define XTHREE_ANIMATION_UTILS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // animation_utils declaration
    //

    template<class D>
    class xanimation_utils : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xanimation_utils();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using animation_utils = xw::xmaterialize<xanimation_utils>;

    using animation_utils_generator = xw::xgenerator<xanimation_utils>;

    //
    // animation_utils implementation
    //


    template <class D>
    inline void xanimation_utils<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xanimation_utils<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xanimation_utils<D>::xanimation_utils()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xanimation_utils<D>::set_defaults()
    {
        this->_model_name() = "AnimationUtilsModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xanimation_utils>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xanimation_utils>>;
    extern template class xw::xgenerator<xthree::xanimation_utils>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xanimation_utils>>;
#endif

#endif