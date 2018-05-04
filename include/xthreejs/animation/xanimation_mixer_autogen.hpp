#ifndef XTHREE_ANIMATION_MIXER_HPP
#define XTHREE_ANIMATION_MIXER_HPP

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
    // animation_mixer declaration
    //

    template<class D>
    class xanimation_mixer : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, rootObject);
        XPROPERTY(double, derived_type, time, 0);
        XPROPERTY(double, derived_type, timeScale, 1);


    protected:

        xanimation_mixer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using animation_mixer = xw::xmaterialize<xanimation_mixer>;

    using animation_mixer_generator = xw::xgenerator<xanimation_mixer>;

    //
    // animation_mixer implementation
    //


    template <class D>
    inline void xanimation_mixer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(rootObject, state, buffers);
        xw::set_patch_from_property(time, state, buffers);
        xw::set_patch_from_property(timeScale, state, buffers);
    }

    template <class D>
    inline void xanimation_mixer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(rootObject, patch, buffers);
        xw::set_property_from_patch(time, patch, buffers);
        xw::set_property_from_patch(timeScale, patch, buffers);
    }

    template <class D>
    inline xanimation_mixer<D>::xanimation_mixer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xanimation_mixer<D>::set_defaults()
    {
        this->_model_name() = "AnimationMixerModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xanimation_mixer>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xanimation_mixer>>;
    extern template class xw::xgenerator<xthree::xanimation_mixer>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xanimation_mixer>>;
#endif

#endif