#ifndef XTHREE_FLY_CONTROLS_HPP
#define XTHREE_FLY_CONTROLS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xcontrols_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // fly_controls declaration
    //

    template<class D>
    class xfly_controls : public xcontrols<D>
    {
    public:

        using base_type = xcontrols<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, moveVector, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, rotationVector, vector3({0,0,0}));
        XPROPERTY(double, derived_type, movementSpeed, 1);
        XPROPERTY(double, derived_type, rollSpeed, 0.05);
        XPROPERTY(double, derived_type, syncRate, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xfly_controls();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using fly_controls = xw::xmaterialize<xfly_controls>;

    using fly_controls_generator = xw::xgenerator<xfly_controls>;

    //
    // fly_controls implementation
    //


    template <class D>
    inline void xfly_controls<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(moveVector, state, buffers);
        xw::set_patch_from_property(rotationVector, state, buffers);
        xw::set_patch_from_property(movementSpeed, state, buffers);
        xw::set_patch_from_property(rollSpeed, state, buffers);
        xw::set_patch_from_property(syncRate, state, buffers);
    }

    template <class D>
    inline void xfly_controls<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(moveVector, patch, buffers);
        xw::set_property_from_patch(rotationVector, patch, buffers);
        xw::set_property_from_patch(movementSpeed, patch, buffers);
        xw::set_property_from_patch(rollSpeed, patch, buffers);
        xw::set_property_from_patch(syncRate, patch, buffers);
    }

    template <class D>
    inline xfly_controls<D>::xfly_controls()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfly_controls<D>::set_defaults()
    {
        this->_model_name() = "FlyControlsModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xfly_controls>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xfly_controls>;
        extern template xw::xmaterialize<xthree::xfly_controls>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xfly_controls>>;
        extern template class xw::xgenerator<xthree::xfly_controls>;
        extern template xw::xgenerator<xthree::xfly_controls>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xfly_controls>>;
    #endif
#endif

#endif