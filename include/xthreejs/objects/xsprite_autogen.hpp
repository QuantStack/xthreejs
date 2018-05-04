#ifndef XTHREE_SPRITE_HPP
#define XTHREE_SPRITE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // sprite declaration
    //

    template<class D>
    class xsprite : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, material);


    protected:

        xsprite();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using sprite = xw::xmaterialize<xsprite>;

    using sprite_generator = xw::xgenerator<xsprite>;

    //
    // sprite implementation
    //


    template <class D>
    inline void xsprite<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(material, state, buffers);
    }

    template <class D>
    inline void xsprite<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(material, patch, buffers);
    }

    template <class D>
    inline xsprite<D>::xsprite()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xsprite<D>::set_defaults()
    {
        this->_model_name() = "SpriteModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xsprite>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xsprite>>;
    extern template class xw::xgenerator<xthree::xsprite>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xsprite>>;
#endif

#endif